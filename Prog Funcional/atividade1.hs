main = do
    la <- getLine
    let a = read la
    lb <- getLine
    let b = read lb
    lc <- getLine
    let c = read lc
    putStrLn $ saida a b c

-- Verifica se os valores são correspondentes ao lado de um triângulo
ehTriangulo a b c
    | a + b < c = False 
    | a + c < b = False 
    | c + b < a = False 
    |otherwise = True

-- Produz a saída a ser escrita
saida a b c
    | ehTriangulo a b c =  show $ heron a b c
    | otherwise = "-"

-- Aplica a fórmula de Heron
heron a b c = sqrt ex1
    where
        ex1 = sp*(sp-a)*(sp-b)*(sp-c)
        sp = (a + b + c)/2

