#ifndef SRC_VIEW_MODEL_IEDITABLE_H_
#define SRC_VIEW_MODEL_IEDITABLE_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

namespace view_model {

class IEditable {
 public:
    IEditable() = default;
    virtual ~IEditable() = default;
    virtual bool renderSelectableItem(bool is_selected) = 0;
    virtual void renderEditWindow() = 0;
    virtual bool getIsMarkedToDelete() const = 0;
};
}  // namespace view_model

#endif  // SRC_VIEW_MODEL_IEDITABLE_H_
