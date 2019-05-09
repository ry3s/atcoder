
let rec f n a res =
  if n = 0 then res
  else f (n/a) a (res + (n mod a))

let () =
  let n = Scanf.scanf "%d\n" (fun x -> x) in
  Array.init (n+1) (fun x ->
      (f x 6 0) + (f (n-x) 9 0))
|> Array.fold_left min n
|> Printf.printf "%d\n" 
