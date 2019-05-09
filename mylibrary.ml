let split_string s =
  let rec f i = if i >= String.length s then [] else s.[i] :: f (i+1) in f 0
                                                                       
let rec list_init n f =
  if n <= 0 then [] else let x = f () in x :: list_init (n-1) f

let rec power x n =
  if n <= 0 then 1
  else if n mod 2 = 0 then
    power (x*x) (n/2)
  else
    x * power x (n - 1)
  
let rec list_char ch = match ch with
    | "" -> []
    | ch -> (String.get ch 0 ) :: (list_char (String.sub ch 1 ((String.length ch) - 1)))           
    
(* range a b = [a; a+1; ... ; b] *)
let rec range a b = if a > b then [] else a :: range (a+1) b
let (>>=) x f = List.map f x |> List.concat
