import csv

def read_csv(filename):
    """Reads a CSV file and returns the data as a list of lists."""
    with open(filename, mode='r', newline='') as file:
        reader = csv.reader(file)
        return [row for row in reader]

def write_csv(filename, data):
    """Writes a list of lists to a CSV file."""
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(data)