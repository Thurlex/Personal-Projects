import unittest
from src.spreadsheet.cell import Cell
from src.spreadsheet.editor import Editor
from src.spreadsheet.grid import Grid

class TestSpreadsheet(unittest.TestCase):

    def setUp(self):
        self.cell = Cell(value="Test")
        self.editor = Editor()
        self.grid = Grid(rows=5, columns=5)

    def test_cell_initialization(self):
        self.assertEqual(self.cell.value, "Test")
        self.assertIsNone(self.cell.formatting)

    def test_editor_set_value(self):
        self.editor.set_value(self.cell, "New Value")
        self.assertEqual(self.cell.value, "New Value")

    def test_grid_add_cell(self):
        self.grid.add_cell(self.cell, row=0, column=0)
        self.assertEqual(self.grid.get_cell(0, 0).value, "Test")

    def test_grid_remove_cell(self):
        self.grid.add_cell(self.cell, row=0, column=0)
        self.grid.remove_cell(row=0, column=0)
        self.assertIsNone(self.grid.get_cell(0, 0))

if __name__ == '__main__':
    unittest.main()