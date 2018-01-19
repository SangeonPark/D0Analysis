#!/bin/bash

arr=(71 72)
range=(144 280)
rm -rf tuplefilesMB.txt
for ((n=0;n<2;n++)); do  

    for ((i=0;i<=${range[$n]};i++)); do
    		echo "/st100-gr1/manca/PbPbData/${arr[$n]}/$i/output/DstSummary.root" >> tuplefilesMB.txt
    	
    done

    
done


