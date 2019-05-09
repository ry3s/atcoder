(* nCr = {(n-r+1)/r}nCr-1 *)
let const = 998244353
let ( *$ ) x y = (x * y) mod const
let ( +$ ) x y = (x + y) mod const
let rec power x n =
  if n <= 0 then 1
  else if n mod 2 = 0 then
    power (x *$ x) (n/2)
  else
    x *$ power x (n - 1)
let mod_inv x =
  power x (const - 2)
  
let () =
  let n, a, b, k = Scanf.scanf "%d %d %d %d"
                     (fun n a b k -> n, a, b, k) in
  let binomial = Array.make (n + 1) 1 in
  for i = 1 to n do
    binomial.(i) <- binomial.(i-1)  *$ (n+1-i) *$ mod_inv i
  done;
  Array.init (n+1) (fun x ->
      let y = (k - a * x) / b in
      if a * x + b * y = k && 0 <= y && y <= n then
        binomial.(x) *$ binomial.(y)
      else
        0)
  |> Array.fold_left (fun x y -> x +$ y) 0
  |> Printf.printf "%d\n"

