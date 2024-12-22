import sys
import os

# Pfad zu deinem `cython`-Ordner
cython_dir = os.path.abspath("./cython")

# Ordner zum Python-Suchpfad hinzufügen
if cython_dir not in sys.path:
    sys.path.insert(0, cython_dir)

# Importiere die `main.pyd`-Datei
import main

if __name__ == "__main__":
    main.run()  # Beispiel: Funktion `run()` aufrufen
