   
let split_string s =
  let rec f i = if i >= String.length s then [] else s.[i] :: f (i+1) in f 0
                                                                       

let () =
  let s = Scanf.scanf "%s" (fun x -> x) in
  let s' = split_string s in
  let s'' = List.rev s' in
  let rec f x =
    match x with
    | [] -> "YES"
    | 'r':: 'e':: 's':: 'a'::'r'::'e'::xs -> f xs
    | 'r':: 'e':: 'm':: 'a':: 'e':: 'r':: 'd':: xs -> f xs
    | 'm':: 'a':: 'e':: 'r':: 'd':: xs -> f xs
    | 'e':: 's':: 'a':: 'r':: 'e' :: xs -> f xs
    | _ -> "NO"
  in
  f s''
|> Printf.printf "%s\n"

