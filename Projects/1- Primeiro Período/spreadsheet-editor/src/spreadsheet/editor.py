class Editor:
    def __init__(self, grid):
        self.grid = grid

    def set_cell_value(self, row, col, value):
        cell = self.grid.get_cell(row, col)
        if cell:
            cell.value = value
            print(f"Cell ({row}, {col}) set to '{value}'")
        else:
            print(f"Cell ({row}, {col}) does not exist.")

    def apply_formatting(self, row, col, formatting):
        cell = self.grid.get_cell(row, col)
        if cell:
            cell.formatting = formatting
            print(f"Formatting applied to cell ({row}, {col}): {formatting}")
        else:
            print(f"Cell ({row}, {col}) does not exist.")