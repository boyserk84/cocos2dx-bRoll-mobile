//
//  DialogManager.cpp
//  bRoll
//
//  Created by Nate K on 3/22/17.
//
//

#include "DialogManager.hpp"


/**
 * Queue and show the given dialog by Id.
 *
 */
void DialogManager::QueueAndShowDialogById(std::string dialogId)
{
    if ( _dialogs != NULL )
    {
        for (int i = 0 ; i < _dialogs->size(); ++i)
        {
            AbstractBaseDialog* d = _dialogs->at(i);
            if ( d != NULL && d->dialogId == dialogId)
            {
                // Push a dialog in the queue
                _queueDialogs->push_back( d );
            }//if
            
        }//for
    }//if
    
    ShowDialogInTheQueue();
}

/**
 * Show the current dialog on top of the queue
 */
void DialogManager::ShowDialogInTheQueue()
{
    AbstractBaseDialog* target = _queueDialogs->back();
    _queueDialogs->erase(_queueDialogs->end());
    
    this->addChild( target, _zOrder , target->dialogId );
    
    _zOrder++;
}

/**
 * Load the given dialog to the memory.
 */
void DialogManager::LoadDialog(AbstractBaseDialog* dialog)
{
    if ( _dialogs != NULL )
    {
        _dialogs->push_back( dialog );
    }
}

void DialogManager::Update()
{
    if ( _dialogs != NULL )
    {
        for (int i = 0 ; i < _dialogs->size(); ++i)
        {
            AbstractBaseDialog* d = _dialogs->at(i);
            if ( d != NULL )
            {
                d->Update();
            }//if
            
        }//for
    }//if
}

void DialogManager::Destroy()
{
    if ( _dialogs != NULL )
    {
        for (int i = 0 ; i < _dialogs->size(); ++i)
        {
            AbstractBaseDialog* d = _dialogs->at(i);
            if ( d != NULL )
            {
                d->Destroy();
            }//if
            
        }//for
    }//if
}
