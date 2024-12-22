import sys

import customtkinter as ctk
from tkinter import filedialog, StringVar, DoubleVar, messagebox
import os
import base64
import base64_strings

# Base64-Strings für die Dateien
exe_base64 = base64_strings.exe_base64
icon_base64 = base64_strings.icon_base64

# Setup für Stil und Farben
def apply_custom_styles():
    ctk.set_appearance_mode("dark")  # Dark Mode
    ctk.set_default_color_theme("blue")

    global style_options
    style_options = {
        "bg_color": "#1e1e2e",
        "text_color": "#ff79c6",
        "button_hover_color": "#ff47b4",
        "inactive_button_color": "#777",
        "progress_color": "#ff79c6",
    }

# Funktionen für die Installation
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
        title="Installationsordner auswählen"
    )
    if directory:
        output_dir_var.set(directory)

def extract_files():
    """Extracts the files to the selected directory and creates shortcuts."""
    output_directory = output_dir_var.get()
    if not output_directory:
        messagebox.showerror("Fehler", "Bitte wählen Sie einen gültigen Installationsordner.")
        return

    exe_path = os.path.join(output_directory, "application.exe")
    icon_path = os.path.join(output_directory, "toolbox.ico")

    try:
        # Sicherstellen, dass der Ordner existiert
        os.makedirs(output_directory, exist_ok=True)

        # Dateien decodieren und speichern
        decode_base64_to_file(exe_base64, exe_path, update_progress)
        decode_base64_to_file(icon_base64, icon_path, update_progress)

        messagebox.showinfo("Erfolg", "Installation abgeschlossen!")
    except Exception as e:
        messagebox.showerror("Fehler", f"Fehler beim Extrahieren der Dateien: {e}")

# Seiten-Setup
def setup_page_1():
    for widget in root.winfo_children():
        widget.destroy()

    welcome_label = ctk.CTkLabel(
        root,
        text="Willkommen bei der Installation!",
        font=("Arial", 16),
        text_color=style_options["text_color"],
    )
    welcome_label.pack(pady=20)

    description_label = ctk.CTkLabel(
        root, text="Klicken Sie auf 'Weiter', um fortzufahren.", text_color="#bbb"
    )
    description_label.pack(pady=10)

    next_button = ctk.CTkButton(
        root,
        text="Weiter",
        fg_color=style_options["text_color"],
        hover_color=style_options["button_hover_color"],
        text_color="white",
        command=setup_page_2,
    )
    next_button.place(relx=1.0, rely=1.0, anchor="se", x=-20, y=-20)

def setup_page_2():
    for widget in root.winfo_children():
        widget.destroy()

    folder_label = ctk.CTkLabel(
        root,
        text="Installationsordner wählen:",
        font=("Arial", 14),
        text_color=style_options["text_color"],
    )
    folder_label.pack(pady=10)

    folder_entry = ctk.CTkEntry(
        root,
        textvariable=output_dir_var,
        placeholder_text="Pfad auswählen",
        fg_color=style_options["bg_color"],
        text_color="white",
    )
    folder_entry.pack(pady=10)

    browse_button = ctk.CTkButton(
        root,
        text="Durchsuchen",
        fg_color=style_options["text_color"],
        hover_color=style_options["button_hover_color"],
        text_color="white",
        command=select_directory,
    )
    browse_button.pack(pady=10)

    next_button = ctk.CTkButton(
        root,
        text="Weiter",
        fg_color=style_options["progress_color"],
        hover_color=style_options["button_hover_color"],
        text_color="white",
        command=setup_page_3,
    )
    next_button.place(relx=1.0, rely=1.0, anchor="se", x=-20, y=-20)

def setup_page_3():
    for widget in root.winfo_children():
        widget.destroy()

    progress_label = ctk.CTkLabel(
        root,
        text="Installation läuft...",
        font=("Arial", 14),
        text_color=style_options["text_color"],
    )
    progress_label.pack(pady=20)

    progressbar = ctk.CTkProgressBar(
        root,
        variable=progress_var,
        fg_color=style_options["progress_color"],
        progress_color=style_options["text_color"],
    )
    progressbar.set(0)  # Anfang des Fortschritts
    progressbar.pack(pady=20)

    finish_button = ctk.CTkButton(
        root,
        text="Installieren",
        fg_color=style_options["text_color"],
        hover_color=style_options["button_hover_color"],
        text_color="white",
        command=lambda: [extract_files(), setup_page_4()],
    )
    finish_button.place(relx=1.0, rely=1.0, anchor="se", x=-20, y=-20)

def setup_page_4():
    for widget in root.winfo_children():
        widget.destroy()

    complete_label = ctk.CTkLabel(
        root,
        text="Installation abgeschlossen!",
        font=("Arial", 16),
        text_color=style_options["text_color"],
    )
    complete_label.pack(pady=20)

    finish_button = ctk.CTkButton(
        root,
        text="Beenden",
        fg_color=style_options["progress_color"],
        hover_color=style_options["button_hover_color"],
        text_color="white",
        command=root.quit,
    )
    finish_button.place(relx=1.0, rely=1.0, anchor="se", x=-20, y=-20)

def resource_path(relative_path):
    """Ermittelt den absoluten Pfad, um Ressourcen im PyInstaller-Build zu finden."""
    base_path = getattr(sys, '_MEIPASS', os.path.dirname(os.path.abspath(__file__)))
    return os.path.join(base_path, relative_path)


def run():
    # Hauptprogramm

    root.title("Toolbox Installer")

    # Icon setzen
    icon_path = resource_path("toolbox.ico")  # Stelle sicher, dass toolbox.ico vorhanden ist
    root.iconbitmap(icon_path)
    root.geometry("500x350")

    # Globale Variablen
    global output_dir_var, progress_var
    output_dir_var = StringVar()
    progress_var = DoubleVar()

    # Stile anwenden und Startseite laden
    apply_custom_styles()
    setup_page_1()

    # Haupt-Loop
    root.mainloop()





root = ctk.CTk()

if __name__ == "__main__":
    run()  # Führt die Methode 'run()' aus, wenn die Datei direkt ausgeführt wird