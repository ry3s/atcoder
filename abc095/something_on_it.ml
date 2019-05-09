let () =
  let a, b, c = Scanf.scanf "%c%c%c\n" (fun a b c -> a, b, c) in
  700
  |> (+) (if a = 'o' then 100 else 0)
  |> (+) (if b = 'o' then 100 else 0)
  |> (+) (if c = 'o' then 100 else 0)
|> Printf.printf "%d\n"
