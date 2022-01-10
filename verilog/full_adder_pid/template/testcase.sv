 // calculate hamming distance
 fitness[i]  = $countones(~(y3_current[i]  ^ y3_value)) + $countones(~(y2_current[i]  ^ y2_value)) + $countones(~(y1_current[i]  ^ y1_value)) + $countones(~(y0_current[i]  ^ y0_value));
