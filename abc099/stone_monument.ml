let rec sum n =
  if n <= 0 then 0
  else n + sum (n - 1)  

let () =
  let a, b = Scanf.scanf "%d %d\n" (fun a b -> a, b) in
  let tall = sum (b - a) in
  Printf.printf "%d\n" (tall - b) 
  
