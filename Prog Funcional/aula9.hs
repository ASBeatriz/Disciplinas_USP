main = do
  putStrLn $ show $ horaDeAcordar Ter
  putStrLn $ show $ Dom
  putStrLn $ show $ Dom == Seg
  putStrLn $ show $ Dom == Dom
  putStrLn $ show $ elem Ter [Seg, Ter, Qua, Qui, Sex]
  putStrLn $ show $ elem Ter [Seg .. Sex]  -- funciona após deriving Enum
  putStrLn $ show $ Nula
  putStrLn $ show $ criaNo 10
  putStrLn $ show $ adicionaElem 10 $ adicionaElem 30 $ adicionaElem 20 Nula

data DiaDaSemana = Dom | Seg | Ter | Qua | Qui | Sex | Sab
   deriving (Enum)   -- implementa a versão padrão do Enum
--   deriving (Enum, Show)   -- ou assim, pra definir o show automaticamente tbm
--   deriving (Enum, Show, Read, Ord, Eq, Bounded)    -- outros...

horaDeAcordar :: DiaDaSemana -> (Integer, Integer)
horaDeAcordar Sab = (8, 0)
horaDeAcordar Dom = (8, 0)
horaDeAcordar _ = (7, 15)

-- Define o show para aquela classe
instance Show DiaDaSemana where
  show Dom = "Domingo"
  show Seg = "Segunda"  
  show Ter = "Terça"
  show Qua = "Quarta"
  show Qui = "Quinta"
  show Sex = "Sexta"
  show Sab = "Sábado"
  
-- Define a comparação para aquela classe
instance Eq DiaDaSemana where
  Dom == Dom = True 
  Seg == Seg = True 
  Ter == Ter = True 
  Qua == Qua = True 
  Qui == Qui = True 
  Sex == Sex = True 
  Sab == Sab = True
  _ == _ = False
  
-- Arvore binária de busca 
data Arvore = Nula | No Arvore Integer Arvore  -- Construtor No que recebe uma árvore, um inteiro e outra árvore
  deriving (Show, Read, Eq)

criaNo :: Integer -> Arvore
criaNo x = No Nula x Nula

adicionaElem :: Integer -> Arvore -> Arvore
adicionaElem x Nula = criaNo x
adicionaElem x (No esq n dir)
  | x == n = No esq n dir
  | x < n = No (adicionaElem x esq) n dir
  | x > n = No esq n (adicionaElem x dir)
  
  
-- Fazer Arvore binária genérica


-- Fazer outras funções que o prof fez (foto)

  
  