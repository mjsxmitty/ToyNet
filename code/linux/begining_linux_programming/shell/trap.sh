#！/bin/bash

tmp=gao,aaaaaa
title=${tmp%%,*}
echo ${title}

trap 'rm -rf /tmp/my_temp_file_$$' INT
echo "creating file /tmp/my_temp_file_$$"
`date > /tmp/my_temp_file_$$`

echo "enter {CTRL-C} to interrupt ..."
while [ -f /tmp/my_temp_file_$$ ]; do
    echo "file exist ..."
    sleep 1
done
echo "the file no longer exist ..."

trap INT
echo "creating file /tmp/my_temp_file_$$"
`date > /tmp/my_temp_file_$$`

echo "enter {CTRL-C} to interrupt ..."
while [ -f /tmp/my_temp_file_$$ ]; do
    echo "file exist ..."
    sleep 1
done

echo "we never get here"
exit 0