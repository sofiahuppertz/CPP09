import csv

# Open the original CSV file for reading
with open('dogecoin.csv', 'r') as original_file:
  csv_reader = csv.reader(original_file)
  
  # Open the new CSV file for writing
  with open('extracted_columns.csv', 'w', newline='') as new_file:
    csv_writer = csv.writer(new_file)
    
    # Read each row from the original file
    for row in csv_reader:
      # Extract columns 0 and 5 (assuming they exist in the row)
      if len(row) > 5:  # Check if row has at least 6 columns
        extracted_columns = [row[0], row[5]]
        # Write the extracted columns to the new CSV file
        csv_writer.writerow(extracted_columns)