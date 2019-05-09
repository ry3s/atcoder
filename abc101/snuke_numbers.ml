let rec digit_sum x = if x <= 0 then 0 else x mod 10 + digit_sum (x / 10)

let () =
  let k = Scanf.scanf "%d" (fun x -> x) in
  
