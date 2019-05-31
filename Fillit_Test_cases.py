
import os

program = 'fillit'
working_fillit = 'working_fillit'

# READ THESE INSTRUCTIONS FIRST!!!!!
# You must first compile your 'fillit' executable
# then place this python script in your `fillit` root directory 
# run it with `python3 <name_of_script_here>.py`
# Make sure your sample/test files have the correct paths

# the code below is looping through each file in this list
valid_test_files = [
	"./samples/valid_samples/one",
	"./samples/valid_samples/two",
	"./samples/valid_samples/four",
	"./samples/valid_samples/test_8",
	"./samples/valid_samples/test_7",
	"./samples/valid_samples/difficile_26_tet"
]

invalid_test_files = [
	"./samples/invalid_samples/empty",
	"./samples/invalid_samples/42",
	"./samples/invalid_samples/just_a_newline",
	"./samples/invalid_samples/backslash_0",
	"./samples/invalid_samples/all_sharps",
	"./samples/invalid_samples/1_char",
	"./samples/invalid_samples/tetrimino_w_5sharps",
	"./samples/invalid_samples/island",
	"./samples/invalid_samples/long_no_pass",
	"./samples/invalid_samples/double_new_line",
	"./samples/invalid_samples/double_new_line2",
	"./samples/invalid_samples/1_diagonal_tetrimino",
	"./samples/invalid_samples/4_tets_1_diagonal_tetrimino",
	"./samples/invalid_samples/28_tets"
]

# In the for loop below, we're creating a variable called test_file
# and then looping through our test_files list
# SEE MY OUTPUT
print('–––––––––––––– VALID TESTFILES ––––––––––––––\n')
print('We should only see tetriminos\n')
for test_file in valid_test_files:
	print('———————————————————————————————————————————')
	print(f'TESTFILE: {test_file}')
	os.system (f'./{program} {test_file}\n')
	print('———————————————————————————————————————————')


# INVALID FILE OUTPUT'S SHOULD ALL SAY ERROR
print('\n')
print('–––––––––––––– INVALID TESTFILES ––––––––––––––\n')
print('We should only see "error"')

for test_file in invalid_test_files:
	print('———————————————————————————————————————————')
	print(f'\nTESTFILE: {test_file}\n')
	os.system (f'./{program} {test_file}')
	print('\n———————————————————————————————————————————')











# COMPARE OUTPUT TO WORKING FILLIT
# for test_file in test_files:
# 	os.system(f'echo "———————————————————————————————————————————"')
# 	os.system(f'echo 'TESTFILE: {test_file}')
# 	os.system(f'./{working_fillit} {test_file} > output_A')
# 	os.system(f'echo "———————————————   VS  ———————————————————"')
# 	os.system(f'./{program} {test_file} > output_B')
# 	os.system(f'diff output_A output_B')

# os.system(f'echo "——————————————————————————————————"')
