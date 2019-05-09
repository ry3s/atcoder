(* range a b = [a; a+1; ... ; b] *)
let rec range a b = if a > b then [] else a :: range (a+1) b
let (>>=) x f = List.map f x |> List.concat
 
let () =
  let a, b, c, x = Scanf.scanf "%d %d %d %d" (fun a b c x -> a, b, c, x) in
  (range 0 a >>= fun i ->
   range 0 b >>= fun j ->
   range 0 c >>= fun k -> [(i, j, k)])
  |> List.filter (fun (i, j, k) -> 500 * i + 100 * j + 50 * k = x)
  |> List.length
  |> Printf.printf "%d\n"
       
