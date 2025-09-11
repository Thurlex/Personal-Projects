# src/utils/formatter.py

def format_number(value, decimal_places=2):
    """Format a number to a specified number of decimal places."""
    try:
        formatted_value = f"{float(value):.{decimal_places}f}"
        return formatted_value
    except ValueError:
        return value  # Return the original value if conversion fails

def format_date(value, date_format="%Y-%m-%d"):
    """Format a date string to a specified format."""
    from datetime import datetime
    try:
        date_obj = datetime.strptime(value, "%Y-%m-%d")
        formatted_date = date_obj.strftime(date_format)
        return formatted_date
    except ValueError:
        return value  # Return the original value if conversion fails

def format_currency(value, currency_symbol="$", decimal_places=2):
    """Format a number as currency."""
    formatted_value = format_number(value, decimal_places)
    return f"{currency_symbol}{formatted_value}"