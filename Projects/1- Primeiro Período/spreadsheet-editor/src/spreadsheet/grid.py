class Cell:
    def __init__(self, value="", formatting=None):
        self.value = value
        self.formatting = formatting

    def set_value(self, value):
        self.value = value

    def get_value(self):
        return self.value

    def set_formatting(self, formatting):
        self.formatting = formatting

    def get_formatting(self):
        return self.formatting


class Grid:
    def __init__(self, rows=10, columns=10):
        self.rows = rows
        self.columns = columns
        self.cells = [[Cell() for _ in range(columns)] for _ in range(rows)]

    def get_cell(self, row, column):
        return self.cells[row][column]

    def set_cell_value(self, row, column, value):
        self.cells[row][column].set_value(value)

    def get_cell_value(self, row, column):
        return self.cells[row][column].get_value()

    def add_row(self):
        self.cells.append([Cell() for _ in range(self.columns)])
        self.rows += 1

    def remove_row(self):
        if self.rows > 0:
            self.cells.pop()
            self.rows -= 1

    def add_column(self):
        for row in self.cells:
            row.append(Cell())
        self.columns += 1

    def remove_column(self):
        if self.columns > 0:
            for row in self.cells:
                row.pop()
            self.columns -= 1