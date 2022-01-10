 // calculate hamming distance
 fitness[i]  = $countones(~(out_current[i]  ^ out)) + $countones(~(next_state_current[i]  ^ next))
