let rec list_init n f =
  if n <= 0 then [] else let x = f () in x :: list_init (n-1) f

let rec iter d xi n li =
  match li with
  | [] -> n
  | xj::xs ->
     if (xj - xi) <= d  then
       let jk = iter d xj 0 xs in
       (if jk > 0 then
          n + jk
        else
          iter d xi n xs)
     else
       let jk = iter d xj 0 xs in
       (if jk = 0 then
          n + 1
        else
          iter d xi n xs)
       
