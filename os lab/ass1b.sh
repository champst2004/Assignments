#!/bin/bash

mkdir dirOne
cd dirOne
mkdir dirTwo
cat > st.txt
cp st.txt st2.txt
mv st2.txt st3.txt
chmod 744 st3.txt
ls -l