import base64
import os
from tkinter import Tk, Button, Label, Entry, filedialog, messagebox, StringVar, DoubleVar, Frame, Text
from tkinter.ttk import Progressbar, Style
import base64_strings

# Base64-Strings für die Dateien
exe_base64 = base64_strings.exe_base64
icon_base64 = base64_strings.icon_base64


def decode_base64_to_file(base64_str, output_path, progress_callback=None):
    """Decodes a Base64 string and writes it to a file."""
    data = base64.b64decode(base64_str)
    total_bytes = len(data)
    chunk_size = 1024
    with open(output_path, 'wb') as file:
        for i in range(0, total_bytes, chunk_size):
            file.write(data[i:i + chunk_size])
            if progress_callback:
                progress_callback(min((i + chunk_size) / total_bytes * 100, 100))


def update_progress(value):
    """Updates the progress bar."""
    progress_var.set(value)
    root.update_idletasks()


def select_directory():
    """Opens a directory selection dialog."""
    directory = filedialog.askdirectory(
        title="Select Output Directory",
        initialdir=output_dir_var.get() or os.path.expandvars('%PROGRAMFILES(X86)%')
    )
    if directory:
        os.makedirs(directory, exist_ok=True)  # Create the folder if it doesn't exist
        output_dir_var.set(directory)


def create_shortcut(target, shortcut_name, icon_path):
    """Creates shortcuts on Desktop and Startup folder."""
    desktop = os.path.join(os.environ['USERPROFILE'], 'Desktop')
    path = os.path.join(desktop, shortcut_name + ".lnk")

    startup = os.path.join(os.getenv('APPDATA'), r'Microsoft\Windows\Start Menu\Programs\Startup')
    startup_shortcut = os.path.join(startup, shortcut_name + ".lnk")

    vbs_script = f'''
    Set oWS = WScript.CreateObject("WScript.Shell")
    sLinkFile = "{path}"
    Set oLink = oWS.CreateShortcut(sLinkFile)
    oLink.TargetPath = "{target}"
    oLink.IconLocation = "{icon_path}"
    oLink.Save
    '''
    startup_vbs_script = f'''
    Set oWS = WScript.CreateObject("WScript.Shell")
    sLinkFile = "{startup_shortcut}"
    Set oLink = oWS.CreateShortcut(sLinkFile)
    oLink.TargetPath = "{target}"
    oLink.IconLocation = "{icon_path}"
    oLink.Save
    '''

    for script, output in [(vbs_script, "create_shortcut.vbs"), (startup_vbs_script, "create_startup_shortcut.vbs")]:
        with open(output, "w") as file:
            file.write(script)
        os.system(f"wscript {output}")
        os.remove(output)


def extract_files():
    """Extracts the files to the selected directory and creates shortcuts."""
    output_directory = output_dir_var.get()
    if not output_directory:
        messagebox.showerror("Error", "Please select a valid output directory.")
        return

    exe_path = os.path.join(output_directory, "application.exe")
    icon_path = os.path.join(output_directory, "toolbox.ico")

    try:
        # Ensure the output directory exists
        os.makedirs(output_directory, exist_ok=True)

        # Decode and save files
        decode_base64_to_file(exe_base64, exe_path, update_progress)
        decode_base64_to_file(icon_base64, icon_path, update_progress)

        # Create shortcuts
        create_shortcut(exe_path, "Toolbox", icon_path)

        messagebox.showinfo("Success", "Installation abgeschlossen!")
    except Exception as e:
        messagebox.showerror("Error", f"Failed to extract files: {e}")


def show_readme():
    """Displays the final README page."""
    readme_window = Frame(root, bg='#2e2e2e')
    readme_window.pack(fill='both', expand=True)
    Label(readme_window, text="Installation abgeschlossen!", bg="#2e2e2e", fg="white", font=("Helvetica", 16)).pack(
        pady=20)
    readme_text = Text(readme_window, bg="#444", fg="white", wrap='word', height=10, width=50)
    readme_text.insert('1.0',
                       "Vielen Dank, dass Sie 'Toolbox' installiert haben!\n\nWeitere Informationen finden Sie auf unserer Website.")
    readme_text.configure(state='disabled')
    readme_text.pack(pady=10)
    button = Button(readme_window, text="Beenden", command=root.quit)
    button.place(relx=0.9, rely=0.9, anchor='se')


def next_page():
    """Handles the navigation between pages."""
    global current_page
    if current_page == 1:
        setup_page_2()
    elif current_page == 2:
        extract_files()
        setup_page_3()


def setup_page_1():
    """Sets up the welcome page."""
    global current_page
    current_page = 1
    welcome_page = Frame(root, bg='#2e2e2e')
    welcome_page.pack(fill='both', expand=True)

    Label(welcome_page, text="Willkommen beim Installer!", bg="#2e2e2e", fg="white", font=("Helvetica", 16)).pack(
        pady=20)
    Label(welcome_page, text="Klicken Sie auf 'Weiter', um fortzufahren.", bg="#2e2e2e", fg="white").pack(pady=10)

    # Button unten rechts positionieren
    button = Button(welcome_page, text="Weiter", command=lambda: (welcome_page.pack_forget(), next_page()))
    button.place(relx=0.9, rely=0.9, anchor='se')  # Position relativ, unten rechts ankern


def setup_page_2():
    """Sets up the installation folder selection page."""
    global current_page
    current_page = 2
    folder_page = Frame(root, bg='#2e2e2e')
    folder_page.pack(fill='both', expand=True)

    Label(folder_page, text="Installationsordner wählen:", bg="#2e2e2e", fg="white").pack(pady=5)
    Entry(folder_page, textvariable=output_dir_var, width=50).pack(pady=5)
    Button(folder_page, text="Durchsuchen...", command=select_directory).pack(pady=5)
    button = Button(folder_page, text="Weiter", command=lambda: (folder_page.pack_forget(), next_page()))
    button.place(relx=0.9, rely=0.9, anchor='se')


def setup_page_3():
    """Sets up the installation progress page."""
    global current_page
    current_page = 3
    progress_page = Frame(root, bg='#2e2e2e')
    progress_page.pack(fill='both', expand=True)

    Label(progress_page, text="Installation läuft...", bg="#2e2e2e", fg="white").pack(pady=20)
    progress_bar = Progressbar(progress_page, orient='horizontal', length=400, variable=progress_var,
                               style='Horizontal.TProgressbar')
    progress_bar.pack(pady=10)
    button = Button(progress_page, text="Weiter", command=lambda: (progress_page.pack_forget(), show_readme()))
    button.place(relx=0.9, rely=0.9, anchor='se')


# Tkinter Setup
root = Tk()
root.title("Installer")
root.geometry("500x350")

# Darkmode Style
style = Style(root)
style.theme_use('clam')
style.configure('TLabel', background='#2e2e2e', foreground='white', font=('Helvetica', 12))
style.configure('TButton', background='#444', foreground='white', font=('Helvetica', 10))
style.configure('Horizontal.TProgressbar', troughcolor='#444', background='#5a9')
root.configure(background='#2e2e2e')

output_dir_var = StringVar(value=os.path.join(os.environ['PROGRAMFILES(X86)'], "Toolbox"))
progress_var = DoubleVar()
current_page = 0

setup_page_1()
root.mainloop()