#!/bin/bash
p=$(echo "scale=2;l($1)/l(10)" | bc -l)
echo "The Common logaroithm of $1 is $p"
