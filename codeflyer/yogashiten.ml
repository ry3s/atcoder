let list_of_str s =
  let rec f i = if i >= String.length s then [] else s.[i] :: f (i+1) in f 0
;;
let () =
  let a, b, n, s = Scanf.scanf "%d %d %d %s" (fun a b c s -> a, b, c, s) in
  let strli = list_of_str s in
  let rec iter a b li =
    match li with
    | [] -> (a, b)
    | 'S' :: xs ->
       if a > 0 then iter (a - 1) b xs
       else
         iter a b xs
    | 'C' :: xs ->
       if b > 0 then iter a (b - 1) xs
       else
         iter a b xs
    | 'E' :: xs ->
       if a >= b && a > 0 then
         iter (a - 1) b xs
       else if b > a && b > 0 then
         iter a (b - 1) xs
       else
         iter a b xs
  in
  let (resta, restb) = iter a b strli in
  print_int resta; print_string "\n"; print_int restb

  

