#!/bin/bash
touch trace/map/diff.log
printf "DIFF FOR CONSTRUCTOR\n" > trace/map/diff.log;
diff trace/map/ft/construct_log.txt trace/map/std/construct_log.txt >> trace/map/diff.log;
printf "\nDIFF FOR DELETES\n">> trace/map/diff.log;
diff trace/map/ft/delete_log.txt trace/map/std/delete_log.txt >> trace/map/diff.log;
printf "\nDIFF FOR Insert\n">> trace/map/diff.log;
diff trace/map/ft/insert_log.txt trace/map/std/insert_log.txt >> trace/map/diff.log;
printf "\nDIFF FOR Iterators\n">> trace/map/diff.log;
diff trace/map/ft/iterators_log.txt trace/map/std/iterators_log.txt >> trace/map/diff.log;
printf "\nDIFF FOR Utilities\n">> trace/map/diff.log;
diff trace/map/ft/utilities_log.txt trace/map/std/utilities_log.txt >> trace/map/diff.log;
printf "\nDIFF FOR Operators\n">> trace/map/diff.log;
diff trace/map/ft/relation_log.txt trace/map/std/relation_log.txt >> trace/map/diff.log;
