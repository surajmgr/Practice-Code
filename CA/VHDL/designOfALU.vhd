library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use ieee.std_logic_unsigned.all;

entity alu_d is
 Port ( inp_a : in signed(3 downto 0);
 inp_b : in signed(3 downto 0);
 sel : in STD_LOGIC_VECTOR (2 downto 0);
 out_alu : out signed(3 downto 0));
end alu_d;

architecture Behavioral of alu_d is
begin
process(inp_a, inp_b, sel) 
begin
case sel is
 when "000" => 
 out_alu<= inp_a + inp_b; --addition 
 when "001" => 
 out_alu<= inp_a - inp_b; --subtraction 
 when "010" => 
 out_alu<= inp_a - 1; --sub 1 
 when "011" => 
 out_alu<= inp_a + 1; --add 1 
 when "100" => 
 out_alu<= inp_a and inp_b; --AND gate 
 when "101" => 
 out_alu<= inp_a or inp_b; --OR gate 
 when "110" => 
 out_alu<= not inp_a ; --NOT gate 
 when "111" => 
 out_alu<= inp_a xor inp_b; --XOR gate 
 when others =>
 NULL;
end case;  
end process; 
end Behavioral;

Alternative ALU
library ieee;

use ieee.std_logic_1164.all;

use ieee.numeric_std.all;

use ieee.std_logic_unsigned.all;



entity ALU is
  
port(
    
selection_line : in std_logic_vector(2 downto 0);
    
a : in std_logic_vector(3 downto 0);
    
b : in std_logic_vector(3 downto 0);
    
ans : out std_logic_vector(3 downto 0)
    
);

end ALU;


architecture ALU_arc of ALU is

begin
  
process (selection_line, a, b) is

begin
  
if (selection_line = "000") then  
 
 ans <= a + b;
  
 elsif (selection_line = "001") then
   
  ans <= a - b;     
  
  elsif (selection_line = "010") then
    
  ans <= a-1;
  
  elsif (selection_line = "011") then
   
   ans <= a + 1;
  
   elsif (selection_line = "100") then
    
   ans <= a and b;
   
   elsif (selection_line = "101") then
   
    ans <= a or b;
  
    elsif (selection_line = "110") then
   
     ans <= not(a);
  
     else
    
     ans <= a xor b;
  
     end if;
  
     end process;

     end ALU_arc;


-- The process is the key structure in behavioral VHDL modeling. A process is the only means by which the executable functionality of a component is defined. In fact, for a model to be capable of being simulated, all components in the model must be defined using one or more processes.
-- Statements within a process are executed sequentially (although care needs to be used in signal assignment statements since they do not take effect immediately; this was covered in the VHDL Basics module when the VHDL timing model was discussed). Variables are used as internal place holders which take on their assigned values immediately.
-- All processes in a VHDL description are executed concurrently. That is, although statements within a process are evaluated and executed sequentially, all processes within the model begin executing concurrently.
