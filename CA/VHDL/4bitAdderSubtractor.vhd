library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity addsub is
   port( E: in std_logic;
          a  : in std_logic_vector(3 downto 0);
          b  : in std_logic_vector(3 downto 0);
          s  : out std_logic_vector(3 downto 0);
          cf : out std_logic;
          ovf : out std_logic);
end addsub;
architecture struct of addsub is
signal c: std_logic_vector(4 downto 0);
signal bx: std_logic_vector(3 downto 0);
begin
bx <= b xor E & E & E & E;
c(0) <= E;
s <= a xor bx xor c(3 downto 0);
c(4 downto 1) <= (a and bx) or (c(3 downto 0) and (a xor bx));
cf <= c(4);
ovf <= c(3) xor c(4);
end struct;

-- LineBreaker
library ieee;
use ieee.std_logic_1164.all;
entity addsub is
   port( OP: in std_logic;
          A,B  : in std_logic_vector(3 downto 0);
          R  : out std_logic_vector(3 downto 0);
          Cout, OVERFLOW : out std_logic);
end addsub;

architecture struct of addsub is
component Full_Adder is
  port( X, Y, Cin : in std_logic;
        sum, Cout : out std_logic);
end component;
signal C1, C2, C3, C4: std_logic;
signal TMP: std_logic_vector(3 downto 0);

begin
TMP <= B xor OP& OP&OP;
FA0:Full_Adder port map(A(0),TMP(0),OP, R(0),C1);-- R0
FA1:Full_Adder port map(A(1),TMP(1),C1, R(1),C2);-- R1
FA2:Full_Adder port map(A(2),TMP(2),C2, R(2),C3);-- R2
FA3:Full_Adder port map(A(3),TMP(3),C3, R(3),C4);-- R3
OVERFLOW <= C3 XOR C4 ;
Cout <= C4;
end struct;
