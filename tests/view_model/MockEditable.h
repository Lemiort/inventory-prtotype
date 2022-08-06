#ifndef TESTS_VIEW_MODEL_MOCKEDITABLE_H_
#define TESTS_VIEW_MODEL_MOCKEDITABLE_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "gmock/gmock.h"
#include "view_model/IEditable.h"

class MockEditable : public view_model::IEditable {
 public:
    MOCK_METHOD(bool, renderSelectableItem, (bool), (override));
    MOCK_METHOD(void, renderEditWindow, (), (override));
    MOCK_METHOD(bool, getIsMarkedToDelete, (), (const, override));
};

#endif  // TESTS_VIEW_MODEL_MOCKEDITABLE_H_
