main = do 
    -- Leitura dos inteiros
    la <- getLine
    let a = read la
    lb <- getLine
    let b = read lb
    -- Imprime resultados
    putStrLn $ show $ tamLista $ filtra ((== "defeituoso").(segundo)) $ zipa_define [a..b] 
    putStrLn $ show $ tamLista $ filtra ((== "perfeito").(segundo)) $ zipa_define [a..b] 
    putStrLn $ show $ tamLista $ filtra ((== "abundante").(segundo)) $ zipa_define [a..b] 

-- Função que recebe um inteiro e devolve uma lista com seus divisores positivos, exceto ele mesmo.
divisores :: Integer -> [Integer]
divisores x = filtra ((== 0).(x `mod`)) [1..(x-1)]

-- Função que recebe uma lista e devolve outra lista apenas com os elementos que passam no teste.
filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra teste (x:xs) 
    | teste x = x: filtra teste xs
    | otherwise = filtra teste xs

-- Função que soma os elementos de uma lista
somaElem :: (Num a)  => [a] -> a
somaElem [] = 0
somaElem (x:xs) = x + somaElem xs

-- Função que recebe um inteiro e retorna uma string de acordo com o seu tipo.
defineNum :: Integer -> String
defineNum x
    | soma == x = "perfeito"
    | soma > x = "abundante"
    | soma < x = "defeituoso"
    where 
        soma = somaElem $ divisores x

-- Função que retorna o tamanho de uma lista
tamLista :: [a] -> Integer
tamLista [] = 0
tamLista (x:xs) = 1 + tamLista xs

-- Função que zipa os elementos de uma lista de inteiros com sua definição.
zipa_define :: [Integer] -> [(Integer, String)]
zipa_define [] = []
zipa_define (x:xs) = (x, defineNum x): zipa_define xs

-- Funções que retornam o primeiro e segundo elemento de uma tupla, respectivamente.
primeiro :: (a, b) -> a
primeiro (x, _) = x
segundo :: (a, b) -> b
segundo (_, x) = x