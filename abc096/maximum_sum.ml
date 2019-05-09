let rec power x n =
  if n <= 0 then 1
  else if n mod 2 = 0 then
    power (x*x) (n/2)
  else
    x * power x (n - 1)

let () =
  let a, b, c, k = Scanf.scanf "%d %d %d %d" (fun a b c k -> a, b, c, k) in
  let result = a + b + c + (max (max a b) c) * (power 2 k - 1) in
  Printf.printf "%d\n" result
