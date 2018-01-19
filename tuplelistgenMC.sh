#!/bin/bash

arr=(21)
range=(9)
rm -rf tuplefilesMB.txt
for ((n=0;n<1;n++)); do  

    for ((i=0;i<=${range[$n]};i++)); do
    		echo "/st100-gr1/manca/PbPbMC/D0inKPi/${arr[$n]}/$i/output/Tuple_d0_simu_pPb.root" >> tuplefilesMC.txt
    	
    done

    
done


