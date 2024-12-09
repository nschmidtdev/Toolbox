import base64


def encode_file_to_base64(file_path):
    with open(file_path, 'rb') as file:
        return base64.b64encode(file.read()).decode('utf-8')


# Base64-kodierte Strings generieren
exe_base64 = encode_file_to_base64("D:/Repos/toolbox/cmake-build-release-visual-studio/Toolbox.exe")
icon_base64 = encode_file_to_base64("D:/Repos/toolbox/cmake-build-release-visual-studio/toolbox.ico")

# Base64-Strings in eine Python-Datei schreiben
with open("base64_strings.py", 'w') as py_file:
    py_file.write(f'exe_base64 = """{exe_base64}"""\n\n')
    py_file.write(f'icon_base64 = """{icon_base64}"""\n\n')

print("Base64-Daten erfolgreich in die Python-Datei gespeichert.")