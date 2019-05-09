let rec digit_sum x = if x <= 0 then 0 else x mod 10 + digit_sum (x / 10)
                    
let () =
  let n = Scanf.scanf "%d\n"
            (fun x -> x) in
  Printf.printf "%s\n"  (if n mod (digit_sum n) = 0 then
                           "Yes"
                         else
                           "No")
      
