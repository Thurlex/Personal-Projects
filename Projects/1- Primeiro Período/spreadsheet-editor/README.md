# README.md

# Homemade Spreadsheet Editor

Welcome to the Homemade Spreadsheet Editor! This project is a simple spreadsheet application that allows users to create, edit, and manage spreadsheets in a user-friendly manner.

## Features

- Create new spreadsheets
- Open existing spreadsheets
- Edit cell values and formatting
- Import and export data in CSV format

## Project Structure

```
spreadsheet-editor
├── src
│   ├── __init__.py
│   ├── main.py
│   ├── spreadsheet
│   │   ├── __init__.py
│   │   ├── cell.py
│   │   ├── editor.py
│   │   └── grid.py
│   └── utils
│       ├── __init__.py
│       ├── csv_handler.py
│       └── formatter.py
├── tests
│   ├── __init__.py
│   └── test_spreadsheet.py
├── requirements.txt
└── README.md
```

## Installation

To get started, clone the repository and install the required dependencies:

```bash
git clone <repository-url>
cd spreadsheet-editor
pip install -r requirements.txt
```

## Usage

Run the application using the following command:

```bash
python src/main.py
```

Follow the on-screen instructions to create or open a spreadsheet.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.