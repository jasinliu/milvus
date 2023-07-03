// Licensed to the LF AI & Data foundation under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership. The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "storage/FieldDataFactory.h"
#include "common/Json.h"
#include "storage/Exception.h"

namespace milvus::storage {

FieldDataPtr
FieldDataFactory::CreateFieldData(const DataType& type, int64_t dim, int64_t total_num_rows) {
    switch (type) {
        case DataType::BOOL:
            return std::make_shared<FieldData<bool>>(type, total_num_rows);
        case DataType::INT8:
            return std::make_shared<FieldData<int8_t>>(type, total_num_rows);
        case DataType::INT16:
            return std::make_shared<FieldData<int16_t>>(type, total_num_rows);
        case DataType::INT32:
            return std::make_shared<FieldData<int32_t>>(type, total_num_rows);
        case DataType::INT64:
            return std::make_shared<FieldData<int64_t>>(type, total_num_rows);
        case DataType::FLOAT:
            return std::make_shared<FieldData<float>>(type, total_num_rows);
        case DataType::DOUBLE:
            return std::make_shared<FieldData<double>>(type, total_num_rows);
        case DataType::STRING:
        case DataType::VARCHAR:
            return std::make_shared<FieldData<std::string>>(type, total_num_rows);
        case DataType::JSON:
            return std::make_shared<FieldData<milvus::Json>>(type, total_num_rows);
        case DataType::VECTOR_FLOAT:
            return std::make_shared<FieldData<FloatVector>>(dim, type, total_num_rows);
        case DataType::VECTOR_BINARY:
            return std::make_shared<FieldData<BinaryVector>>(dim, type, total_num_rows);
        default:
            throw NotSupportedDataTypeException(GetName() + "::CreateFieldData" + " not support data type " +
                                                datatype_name(type));
    }
}

}  // namespace milvus::storage