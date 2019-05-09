let powers =
  let rec pow b k =
    if k > 1000 then[]
    else k :: pow b (k*b)
  in
  let rec loop b =
    if b > 1000 then []
    else (pow b (b*b)) @ loop (b+1)
  in
  1 :: loop 2

let () =
    let x =
    Scanf.scanf "%d" (fun x -> x) in
    List.filter ((>=) x) powers
    |> List.fold_left max 1
    |> Printf.printf "%d\n"
         
  
