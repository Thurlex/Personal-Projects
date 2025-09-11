# File structure:
# spreadsheet-editor
# ├── src
# │   ├── __init__.py
# │   ├── main.py
# │   ├── spreadsheet
# │   │   ├── __init__.py
# │   │   ├── cell.py
# │   │   ├── editor.py
# │   │   └── grid.py
# │   └── utils
# │       ├── __init__.py
# │       ├── csv_handler.py
# │       └── formatter.py
# ├── tests
# │   ├── __init__.py
# │   └── test_spreadsheet.py
# ├── requirements.txt
# └── README.md

import os
from typing import Dict, Tuple

class SimpleSpreadsheet:
    def __init__(self, rows: int = 5, cols: int = 5):
        self.rows = rows
        self.cols = cols
        self.cells: Dict[Tuple[int, int], str] = {}

    def set_cell(self, row: int, col: int, value: str) -> None:
        if 0 <= row < self.rows and 0 <= col < self.cols:
            self.cells[(row, col)] = value
        else:
            print("Cell position out of range!")

    def get_cell(self, row: int, col: int) -> str:
        return self.cells.get((row, col), "")

    def display(self) -> None:
        # Print column headers
        print("   ", end="")
        for col in range(self.cols):
            print(f"{chr(65 + col):^5}", end="")
        print("\n")

        # Print rows
        for row in range(self.rows):
            print(f"{row+1:2} ", end="")
            for col in range(self.cols):
                print(f"{self.get_cell(row, col):^5}", end="")
            print()

def main():
    sheet = SimpleSpreadsheet()
    
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')
        sheet.display()
        print("\nCommands: set <row> <col> <value>, exit")
        
        command = input("> ").strip().split()
        if not command:
            continue
            
        if command[0] == "exit":
            break
            
        if command[0] == "set" and len(command) >= 4:
            try:
                row = int(command[1]) - 1
                col = ord(command[2].upper()) - ord('A')
                value = " ".join(command[3:])
                sheet.set_cell(row, col, value)
            except ValueError:
                print("Invalid input!")

if __name__ == "__main__":
    main()