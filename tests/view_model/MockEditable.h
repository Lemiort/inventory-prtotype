#ifndef TESTS_VIEW_MODEL_MOCKEDITABLE
#define TESTS_VIEW_MODEL_MOCKEDITABLE

#include "gmock/gmock.h"
#include "view_model/IEditable.h"

namespace view_model {

class MockEditable : public IEditable {
public:
    MOCK_METHOD(bool, renderSelectableItem, (bool), (override));
    MOCK_METHOD(void, renderEditWindow, (), (override));
    MOCK_METHOD(bool, getIsMarkedToDelete, (), (const, override));
};

}  // namespace view_model

#endif /* TESTS_VIEW_MODEL_MOCKEDITABLE */
