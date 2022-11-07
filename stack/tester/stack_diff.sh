#!/bin/bash
touch trace/stack/diff.log
printf "DIFF FOR CONSTRUCTOR\n" > trace/stack/diff.log;
diff trace/stack/ft/stack_log.txt trace/stack/std/stack_log.txt >> trace/stack/diff.log;
exit 0