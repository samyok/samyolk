# Import the required modules
import os

# Define the input file path
input_file = 'input'

# Check if the input file exists
if not os.path.exists(input_file):
  print(f'Error: The input file "{input_file}" does not exist!')
  exit()

# Read the input file
with open(input_file, 'r') as file:
  # Read the input data
  data = file.read()

# Define a variable to store the total sum
total_sum = 0

# Split the input data into groups of three lines
groups = [data[i:i+3] for i in range(0, len(data), 3)]

# Iterate over the groups
for group in groups:
  # Split the group into individual rucksacks
  rucksacks = group.splitlines()

  # Check if the group has at least three rucksacks
  if len(rucksacks) >= 3:
    # Iterate over the items in the first rucksack
    for item in rucksacks[0]:
      # Check if the item exists in the other rucksacks
      if all(item in rucksack for rucksack in rucksacks[1:]):
        # Calculate the priority of the item
        priority = ord(item) - ord('a') + 1 if item.islower() else ord(item) - ord('A') + 27

        # Add the priority to the total sum
        total_sum += priority

        # Stop iterating over the items
        break

# Print the total sum
print(f'The total sum is {total_sum}')
