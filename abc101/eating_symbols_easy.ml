let () =
  let s = Scanf.scanf "%c%c%c%c\n" (fun a b c d -> [a;b;c;d]) in
  List.fold_left (fun sum x ->
      match x with
      | '+' -> sum + 1
      | '-' -> sum -1
    ) 0 s
|> Printf.printf "%d\n" 
