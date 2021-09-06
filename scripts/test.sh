#!bin/sh
workspace=`pwd`
[ ! -d build ] && mkdir build
cd build
cmake ..
make
rm all.log
touch all.log
pass=0
fail=0
all=0
pass_list=()
for file in ${workspace}/tests/*
do
    if test -f $file && [ "${file##*.}"x = "py"x ];then
        echo ${file} >> all.log
        python2 -m compileall ${file}
        ./pythonvm ${file}"c" >> all.log 2>&1
        if [ $? -eq 0 ]; then
          let pass++
          pass_list+=(${file})
        else
          let fail++
        fi
        let all++
    fi
done

echo "all: ${all}, pass: ${pass}, fail: ${fail}"
for i in "${pass_list[@]}"; do
  echo "$i"
done
