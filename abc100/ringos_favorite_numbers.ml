let rec power x n =
  if n <= 0 then 1
  else if n mod 2 = 0 then
    power (x*x) (n/2)
  else
    x * power x (n - 1)
let () =
  let d, n = Scanf.scanf "%d %d" (fun d n -> d, n) in
  let s = Array.init 101 (fun i -> if d = 0 then
                                     (if i = 100 then 101
                                      else i)
                                   else (if i = 100 then
                                           (i+1) * (power 100 d)
                                         else
                                           i * (power 100 d))) in 
  Printf.printf "%d\n" (s.(n))
