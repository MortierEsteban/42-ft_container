#!/bin/bash
touch trace/vector/diff.log
printf "DIFF FOR CONSTRUCTOR\n" > trace/vector/diff.log;
diff trace/vector/ft/construct_log.txt trace/vector/std/construct_log.txt >> trace/vector/diff.log;
printf "\nDIFF FOR DELETES\n">> trace/vector/diff.log;
diff trace/vector/ft/delete_log.txt trace/vector/std/delete_log.txt >> trace/vector/diff.log;
printf "\nDIFF FOR Insert\n">> trace/vector/diff.log;
diff trace/vector/ft/insert_log.txt trace/vector/std/insert_log.txt >> trace/vector/diff.log;
printf "\nDIFF FOR Iterators\n">> trace/vector/diff.log;
diff trace/vector/ft/iterators_log.txt trace/vector/std/iterators_log.txt >> trace/vector/diff.log;
printf "\nDIFF FOR Utilities\n">> trace/vector/diff.log;
diff trace/vector/ft/utilities_log.txt trace/vector/std/utilities_log.txt >> trace/vector/diff.log;
printf "\nDIFF FOR Operators\n">> trace/vector/diff.log;
diff trace/vector/ft/relation_log.txt trace/vector/std/relation_log.txt >> trace/vector/diff.log;
exit 0