//
//  DialogManager.hpp
//  bRoll
//
//  Created by Nate K on 3/22/17.
//
//

#ifndef DialogManager_hpp
#define DialogManager_hpp

#include <stdio.h>
#include "AbstractBaseDialog.hpp"
class DialogManager : public cocos2d::Node {
    
public:
    
    void LoadDialog(AbstractBaseDialog* dialog);
    void QueueAndShowDialogById(std::string dialogId);
    void ShowDialogInTheQueue();
    void Update();
    void Destroy();
    
private:
    /** List of all dialogs being loaded in the game. */
    std::vector<AbstractBaseDialog*> *_dialogs;
    
    /** List of visible dialogs in the game. */
    std::vector<AbstractBaseDialog*> *_queueDialogs;
    
    int _zOrder = 0;
    
};


#endif /* DialogManager_hpp */
