let rec digit_sum x =
  if x <= 0 then 0 else x mod 10 + digit_sum (x/10)

let rec iter a b min n =
  let sum = digit_sum a + digit_sum b in
  if a < n/2 then min
  else if sum < min  then
    iter (a - 1) (b + 1)  sum n
  else
    iter (a - 1) (b + 1)  min n
  ;;
let () =
  let n = Scanf.scanf "%d" (fun x -> x) in
  let min = iter (n - 1) 1 100000 n in
  print_endline (string_of_int min)
