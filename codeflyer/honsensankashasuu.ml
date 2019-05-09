let () =
  Scanf.scanf "%d %d"
    (fun a b ->
      let rec iter y x m =
        if m > y then (m - x) else iter y x (m + x) in
      iter a b 0
    |> Printf.printf "%d\n")
