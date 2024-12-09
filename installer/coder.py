import base64


def encode_file_to_base64(file_path):
    with open(file_path, 'rb') as file:
        return base64.b64encode(file.read()).decode('utf-8')


# Base64-kodierte Strings generieren
exe_base64 = encode_file_to_base64("D:/Repos/toolbox/cmake-build-release-visual-studio/Toolbox.exe")
icon_base64 = encode_file_to_base64("D:/Repos/toolbox/cmake-build-release-visual-studio/toolbox.ico")

# Base64-Strings in Textdateien schreiben
with open("Toolbox_exe_base64.txt", 'w') as exe_file:
    exe_file.write(exe_base64)

with open("Toolbox_icon_base64.txt", 'w') as icon_file:
    icon_file.write(icon_base64)

print("Base64-Daten erfolgreich in Textdateien gespeichert.")