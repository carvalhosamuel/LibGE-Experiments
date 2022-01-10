sem -j 2 'sleep 1;echo 1 finished';   echo sem 1 exited
sem -j 2 'sleep 2;echo 2 finished';   echo sem 2 exited
sem -j 2 'sleep 3;echo 3 finished';   echo sem 3 exited
sem -j 2 'sleep 4;echo 4 finished';   echo sem 4 exited
sem --wait; echo sem --wait done
